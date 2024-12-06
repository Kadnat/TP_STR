import serial
from datetime import datetime
import time

class TimingAnalyzer:
    def __init__(self, port='/dev/tty.usbserial-A603HV93', baudrate=9600):
        self.ser = serial.Serial(port, baudrate, timeout=1)
        self.task_timings = {
            'A': {'timestamp': None},
            'C': {'timestamp': None},
            'E': {'timestamp': None},
            'G': {'timestamp': None},
            'I': {'timestamp': None},
            'K': {'timestamp': None}
        }
        self.task_end_timings = {
            'B': {'timestamp': None},
            'D': {'timestamp': None},
            'F': {'timestamp': None},
            'H': {'timestamp': None},
            'J': {'timestamp': None},
            'L': {'timestamp': None}
        }

    def analyze_timings(self):
        try:
            print("Analyse des temps d'exécution - Appuyez sur Ctrl+C pour arrêter")
            print("-" * 80)
            print(f"{'Début':<10} {'Fin':<10} {'Durée (ms)':<15}")
            print("-" * 80)

            while True:
                if self.ser.in_waiting:
                    char = self.ser.read().decode('utf-8', errors='ignore')
                    current_time = datetime.now()

                    # Début de tâche
                    if char in ['A', 'C', 'E', 'G', 'I', 'K']:
                        self.task_timings[char]['timestamp'] = current_time
                        print(f"Début tâche {char}: {current_time}")

                    # Fin de tâche
                    elif char in ['B', 'D', 'F', 'H', 'J', 'L']:
                        self.task_end_timings[char]['timestamp'] = current_time
                        
                        # Trouver le caractère de début correspondant
                        start_char = chr(ord(char) - 1)
                        
                        # Calculer la durée si on a un début et une fin
                        if (self.task_timings[start_char]['timestamp'] is not None and 
                            self.task_end_timings[char]['timestamp'] is not None):
                            
                            start_time = self.task_timings[start_char]['timestamp']
                            end_time = self.task_end_timings[char]['timestamp']
                            
                            duration = (end_time - start_time).total_seconds() * 1000  # en millisecondes
                            
                            print(f"{start_char:<10} {char:<10} {duration:>7.2f} ms")
                            
                            # Réinitialiser les timestamps
                            self.task_timings[start_char]['timestamp'] = None
                            self.task_end_timings[char]['timestamp'] = None

                time.sleep(0.01)

        except KeyboardInterrupt:
            print("\nArrêt de l'analyse...")
            self.ser.close()

if __name__ == "__main__":
    analyzer = TimingAnalyzer(port='/dev/tty.usbserial-A603HV93', baudrate=9600)
    analyzer.analyze_timings()