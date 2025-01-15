import threading
import time
import serial
import sys

from PyQt5.QtCore import QCoreApplication

from src import globals as g
from src.communication import SerialWorker
from src.decode import decode_trame
from src.controller import control_forklift



def simulate_trame_on_com3():
    """
    Simule l'envoi de trames hexadécimales sur le port COM3.
    La structure de la trame suit celle définie dans la logique précédente.
    """
    # Ouvrir le port COM3
    with serial.Serial('COM3', 9600, timeout=1) as ser:
        print("Port COM3 ouvert pour l'envoi des trames simulées...")

        # Exemples de trames hexadécimales
        trames = [
            "FEC00000646464FF",  # Allumer le moteur
            "C00200646464FF",  # Lever les fourches
            "E00000646464FF",  # Mettre le frein à main
            "200000646464FF",  # Eteindre le moteur
            "E00000646464FF",  # Allumer le moteur
            "C00000646464FF",  # Enlever le frein à main
            "C10056646464FF",  # Avancer
            "C11056646464FF",  # Tourner à droite
            "C12056646464FF",  # Tourner à gauche
            "C20056646464FF",  # Marche arrière
            "C1005678A0B0FF",  # Excès de température
            "C10056789000FF"   # Batterie à 0%
        ]


        # Envoi des trames sur COM3 toutes les 2 secondes
        for trame in trames:
            print("Engine :", g.Engine)
            print("Drive :", g.Drive)
            print("Forklift :", g.Forklift)
            print("HandBrake :", g.HandBrake)
            print("WheelDirection :", g.WheelDirection)
            
            print(f"\n Envoi de la trame : {trame}")
            ser.write(bytes.fromhex(trame))  # Convertir la trame en bytes et l'envoyer sur COM3
            time.sleep(3)  # Attente de 3 secondes entre les trames

        print("Engine :", g.Engine)
        print("Drive :", g.Drive)
        print("Forklift :", g.Forklift)
        print("HandBrake :", g.HandBrake)
        print("WheelDirection :", g.WheelDirection)
        
        print("Trames simulées envoyées avec succès sur COM3.")

def handle_received_data(trame_fragment):
    try:
        # Ajouter les données reçues au buffer
        g.buffer += trame_fragment
        print(f"Buffer actuel : {g.buffer}")

        if "fe" in g.buffer and "ff" in g.buffer:
            # Trouver les indices des délimiteurs
            start_idx = g.buffer.index("fe")

            # Si FF précède FE, supprimer les données invalides avant FE
            if start_idx > g.buffer.index("ff"):
                g.buffer = g.buffer[start_idx:]
                return
            else :
                end_idx = g.buffer.index("ff", start_idx) + 2  # Inclure "FF"

            # Extraire la trame complète
            trame_complete = g.buffer[start_idx:end_idx]
            print(f"Trame complète détectée : {trame_complete}")

            # Réinitialiser le buffer après traitement
            g.buffer = g.buffer[end_idx:]

            g.buffer = "" 
            
            if len(trame_complete) == 20:
                trame_data = decode_trame(trame_complete)
                print(f"Trame décodée : {trame_data}")
                # print("Engine :", g.Engine)
                # print("Drive :", g.Drive)
                # print("Forklift :", g.Forklift)
                # print("HandBrake :", g.HandBrake)
                # print("WheelDirection :", g.WheelDirection)
                # Exécuter les contrôles du chariot élévateur
                control_forklift(trame_data)

    except ValueError as e:
        raise

def main():
    """
    Fonction principale pour démarrer le système de réception de trames
    et de contrôle du chariot élévateur.
    """
    app = QCoreApplication(sys.argv)
    
    time.sleep(5)
    
    # Lancer l'envoi des trames simulées dans un thread séparé
    # trame_thread = threading.Thread(target=simulate_trame_on_com3)
    # trame_thread.start()

    # Initialiser le travailleur série pour la communication UART
    worker = SerialWorker(port='COM8', baudrate=9600)
    worker.data_received.connect(handle_received_data)

    # Démarrer la réception
    print("Démarrage de la réception des trames UART... \n")
    worker.start()

    sys.exit(app.exec_())

if __name__ == "__main__":
    main()
    