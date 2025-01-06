import serial
import pandas as pd
import numpy as np
from datetime import datetime
import os
import time
from typing import Dict, Optional, Union
from serial.serialutil import SerialException

class TimingAnalyzer:
    def __init__(self, port: str = '/dev/tty.usbserial-A603HV93', baudrate: int = 9600):
        """
        Initialise l'analyseur de temps d'exécution.
        """
        try:
            self.ser = serial.Serial(port, baudrate, timeout=1)
        except SerialException as e:
            raise SerialException(f"Erreur lors de l'ouverture du port série {port}: {e}")
        
        # Dictionnaire pour stocker les timestamps de début pour chaque tâche
        self.task_starts = {str(i): None for i in range(1, 7)}
        
        # Dictionnaire de correspondance entre les caractères et les numéros de tâche
        self.start_chars = {'A': '1', 'B': '2', 'C': '3', 'D': '4', 'E': '5', 'F': '6'}
        self.end_chars = {'G': '1', 'H': '2', 'I': '3', 'J': '4', 'K': '5', 'L': '6'}
        
        self.csv_file = 'task_timings.csv'
        self._init_csv()

    def _init_csv(self) -> None:
        """Initialise le fichier CSV avec les colonnes appropriées."""
        if os.path.exists(self.csv_file):
            os.remove(self.csv_file)
            
        df = pd.DataFrame(columns=['Task_Number', 'Duration_ms'])
        df.to_csv(self.csv_file, index=False)

    def analyze_timings(self) -> None:
        """Analyse les temps d'exécution des tâches en temps réel."""
        try:
            print("Analyse des temps d'exécution - Appuyez sur Ctrl+C pour arrêter")
            
            while True:
                if self.ser.in_waiting:
                    char = self.ser.read().decode('utf-8', errors='ignore').strip()
                    if not char:
                        continue
                        
                    current_time = datetime.now()
                    self._process_character(char, current_time)
                    
                time.sleep(0.01)

        except KeyboardInterrupt:
            print("\nArrêt de l'analyse...")
        except Exception as e:
            print(f"Erreur pendant l'analyse: {e}")
        finally:
            self.cleanup()

    def _process_character(self, char: str, current_time: datetime) -> None:
        """Traite un caractère reçu du port série."""
        if char in self.start_chars:
            task_num = self.start_chars[char]
            self.task_starts[task_num] = current_time
            print(f"Début tâche {task_num}: {current_time}")
        elif char in self.end_chars:
            task_num = self.end_chars[char]
            self._handle_task_end(task_num, current_time)

    def _handle_task_end(self, task_num: str, current_time: datetime) -> None:
        """Gère la fin d'une tâche et calcule sa durée."""
        if task_num in self.task_starts and self.task_starts[task_num] is not None:
            start_time = self.task_starts[task_num]
            duration = (current_time - start_time).total_seconds() * 1000  # en millisecondes
            
            # Stocke la durée dans le CSV
            self.add_to_csv(task_num, duration)
            
            print(f"Tâche {task_num}: durée = {duration:.2f} ms")
            
            # Réinitialise le temps de début
            self.task_starts[task_num] = None

    def add_to_csv(self, task_num: str, duration: float) -> None:
        """Ajoute une nouvelle mesure au fichier CSV."""
        try:
            with open(self.csv_file, 'a') as f:
                f.write(f"{task_num},{duration}\n")
        except Exception as e:
            print(f"Erreur lors de l'écriture dans le CSV: {e}")

    def calculate_statistics(self) -> None:
        """Calcule et affiche les statistiques pour chaque tâche."""
        try:
            df = pd.read_csv(self.csv_file)
            print("\nStatistiques des durées par tâche:")
            print("-" * 50)
            
            df['Task_Number'] = df['Task_Number'].astype(str)
            
            for task_num in range(1, 7):
                task_data = df[df['Task_Number'] == str(task_num)]['Duration_ms']
                
                if len(task_data) > 0:
                    mean = task_data.mean()
                    std = task_data.std()
                    min_val = task_data.min()
                    max_val = task_data.max()
                    count = len(task_data)
                    
                    print(f"\nTâche {task_num}:")
                    print(f"  Nombre d'échantillons: {count}")
                    print(f"  Moyenne: {mean:.2f} ms")
                    if count > 1:
                        print(f"  Écart-type: {std:.2f} ms")
                    print(f"  Min: {min_val:.2f} ms")
                    print(f"  Max: {max_val:.2f} ms")
                else:
                    print(f"\nTâche {task_num}: Aucune donnée")

        except Exception as e:
            print(f"Erreur lors du calcul des statistiques: {e}")
            print("Contenu du fichier CSV:")
            try:
                with open(self.csv_file, 'r') as f:
                    print(f.read())
            except Exception as e2:
                print(f"Erreur lors de la lecture du fichier: {e2}")

    def cleanup(self) -> None:
        """Nettoie les ressources et affiche les statistiques finales."""
        if hasattr(self, 'ser') and self.ser.is_open:
            self.ser.close()
        
        self.calculate_statistics()


if __name__ == "__main__":
    try:
        analyzer = TimingAnalyzer(port='/dev/tty.usbserial-A603HV93', baudrate=9600)
        analyzer.analyze_timings()
    except Exception as e:
        print(f"Erreur critique: {e}")