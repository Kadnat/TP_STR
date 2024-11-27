from PyQt5.QtCore import QObject, pyqtSignal, QThread
import serial
from threading import Lock

serial_port_lock = Lock()

class SerialWorker(QObject):
    data_received = pyqtSignal(str)

    def __init__(self, port='COM4', baudrate=9600, timeout=1):
        super().__init__()
        self.serial_port = serial.Serial(port=port, baudrate=baudrate, timeout=timeout)
        self.thread = QThread()
        self.moveToThread(self.thread)
        self.thread.started.connect(self.run)
        self.running = False

    def start(self):
        if not self.thread.isRunning():
            self.running = True
            self.thread.start()

    def stop(self):
        self.running = False
        self.thread.quit()
        self.thread.wait()
        if self.serial_port.is_open:
            self.serial_port.close()

    def run(self):
        """Fonction pour recevoir les trames via UART et les convertir en chaîne hexadécimale."""
        while self.running:
            try:
                if self.serial_port.in_waiting > 0:
                    data_bytes = self.serial_port.read(self.serial_port.in_waiting)  # Lire tous les octets disponibles
                    trame_fragment = data_bytes.hex()
                    self.data_received.emit(trame_fragment)
            except serial.SerialException as e:
                print(f"Exception série : {e}")

# --- Fonction de test associée ---
import time

def test_serial_reception():
    """
    Fonction de test pour simuler la réception d'une trame UART et afficher la trame reçue.
    """
    def handle_received_data(trame_str):
        print(f"Trame reçue (test) : {trame_str}")
        # Ajouter ici les tests unitaires ou des assertions pour vérifier la validité de la trame

    # Initialisation du travailleur série
    worker = SerialWorker(port='COM4', baudrate=9600)
    worker.data_received.connect(handle_received_data)  # Connexion du signal à la fonction de traitement
    worker.start()

    # Simulation du temps de réception des données
    time.sleep(5)  # Laisser le temps à la fonction de recevoir quelques trames (ajuster selon ton besoin)
    
    # Arrêter le thread proprement après le test
    worker.stop()

# Appeler la fonction de test pour lancer la simulation de réception
# test_serial_reception()
