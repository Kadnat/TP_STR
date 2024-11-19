import pyautogui
import time

from src import globals as g
# import globals as g

#############
#   Main    #
#############

def control_forklift(state_dict):
    """
    Cette fonction prend en entrée un dictionnaire contenant les états du forklift
    et simule les actions sur le clavier en fonction des conditions définies.
    """
    # 1. Motor control
    if state_dict['key_presence'] and state_dict['seat_presence']:  # Allumer moteur
        if g.Engine == False:
            pyautogui.press('f')
            g.Engine = True
            print("Start Engine...")
    else:                                                           # Eteindre moteur
        if g.Engine == True:
            pyautogui.press('f')
            g.Engine = False
            print("Stop Engine...")
            
    # 2. Brake control
    if state_dict['hand_brake'] and g.HandBrake == False:           # Activer Frein à main
        pyautogui.press('space')
        g.HandBrake = True
        print("Brake Activated...")
    elif not state_dict['hand_brake'] and g.HandBrake == True:      # Desactiver Frein à main
        pyautogui.press('space')
        g.HandBrake = False
        print("Brake Disactivated...")

    # 3. Forks control
    if state_dict['forks'] == 0 and g.Forklift != 0:     # Broche stationnaire
        pyautogui.keyUp('e')
        pyautogui.keyUp('q')
        g.Forklift = 0
        print("Forks Stationnary...")
    elif state_dict['forks'] == 1 and g.Forklift != 1:   # Baisser les fourches
        pyautogui.keyUp('e')
        pyautogui.keyDown('q')
        g.Forklift = 1
        print("Falling Forks...")
    elif state_dict['forks'] == 2 and g.Forklift != 2:   # Monter les fourches
        pyautogui.keyUp('q')
        pyautogui.keyDown('e')
        g.Forklift = 2
        print("Raising Forks...")

    # 4. Wheels direction control
    if state_dict['wheels_direction'] == 0 and g.WheelDirection != 0:    # Roues tout droit
        pyautogui.keyUp('a')
        pyautogui.keyUp('d')
        g.WheelDirection = 0
        print("Straight wheels ...")
    elif state_dict['wheels_direction'] == 1 and g.WheelDirection != 1:  # Roues à droite
        pyautogui.keyUp('a')
        pyautogui.keyDown('d')
        g.WheelDirection = 1
        print("Right wheels ...")
    elif state_dict['wheels_direction'] == 2 and g.WheelDirection != 2:  # Roues à gauche
        pyautogui.keyUp('d')
        pyautogui.keyDown('a')
        g.WheelDirection = 2
        print("Left wheels ...")

    # 5. Driving control
    if state_dict['drive'] == 0 and g.Drive != 0:       # Point mort
        pyautogui.keyUp('w')
        pyautogui.keyUp('s')
        g.Drive = 0
        print("Neutral ...")
    elif state_dict['drive'] == 1 and g.Drive != 1:     # Move forward
        pyautogui.keyUp('s')
        pyautogui.keyDown('w')
        g.Drive = 1
        print("Move forward ...")
    elif state_dict['drive'] == 2 and g.Drive != 2:     # Move backward 
        pyautogui.keyUp('w')
        pyautogui.keyDown('s')
        g.Drive = 2
        print("Move backward ...")

    # 6. Interruption
    # Choc
    if state_dict['shock'] and g.Engine == True:
        pyautogui.press('f')
        g.Engine = False
    # Température Eau
    if state_dict['water_temp'] > 100 and g.Engine == True :
        pyautogui.press('f')
        g.Engine = False
    # Température Huile
    if state_dict['oil_temp'] > 110 and g.Engine == True:
        pyautogui.press('f')
        g.Engine = False
    # battery
    if state_dict['battery'] <= 0 and g.Engine == True:
        pyautogui.press('f')
        g.Engine = False

#########################
#   Unitary function    #
#########################

def StartEngine():
    print("Simulation : Start Engine...")
    control_forklift({
        "key_presence": True, 
        "seat_presence": True, 
        "hand_brake": False,
        "shock": False, 
        "drive": 0, 
        "wheels_direction": 0, 
        "forks": 0, 
        "water_temp": 90, 
        "oil_temp": 90, 
        "battery": 80
    })
    
def RaisingForks():
    print("Simulation : Lever les fourches")
    control_forklift({
        "key_presence": True, 
        "seat_presence": True, 
        "hand_brake": False,
        "shock": False, 
        "drive": 0, 
        "wheels_direction": 0, 
        "forks": 2, 
        "water_temp": 90, 
        "oil_temp": 90, 
        "battery": 80
    })
    
def RaisingForks():
    print("Simulation : Lever les fourches")
    control_forklift({
        "key_presence": True, 
        "seat_presence": True, 
        "hand_brake": False,
        "shock": False, 
        "drive": 0, 
        "wheels_direction": 0, 
        "forks": 2, 
        "water_temp": 90, 
        "oil_temp": 90, 
        "battery": 80
    })

    
def init_sequence():
    # Allume le moteur
    StartEngine()
    time.sleep(3)
    # Lever le fourches    
    RaisingForks()
    time.sleep(3)
    # Activer frein à main
    print("Simulation : Mettre le frein à main")
    control_forklift({"key_presence": True, "seat_presence": True, "hand_brake": True, "drive": 0, "wheels_direction": 0, "forks": 0, "water_temp": 90, "oil_temp": 90, "battery": 80})
    time.sleep(3)
    # Eteindre le moteur
    print("Simulation : Eteindre le moteur")
    control_forklift({"key_presence": True, "seat_presence": False, "hand_brake": True, "drive": 0, "wheels_direction": 0, "forks": 0, "water_temp": 90, "oil_temp": 90, "battery": 80})
    time.sleep(3)
    
    
def simulate_cmd_sequence():
    """
    Simule une séquence d'actions dans l'ordre demandé pour tester les commandes.
    """
    # Allumer le moteur
    print("Simulation : Allumer le moteur")
    control_forklift({"key_presence": True, "seat_presence": True, "hand_brake": True, "drive": 0, "wheels_direction": 0, "forks": 0, "water_temp": 90, "oil_temp": 90, "battery": 80})
    time.sleep(3)

    # Enlever le frein à main
    print("Simulation : Enlever le frein à main")
    control_forklift({"key_presence": True, "seat_presence": True, "hand_brake": False, "drive": 0, "wheels_direction": 0, "forks": 0, "water_temp": 90, "oil_temp": 90, "battery": 80})
    time.sleep(3)

    # Avancer
    print("Simulation : Avancer")
    control_forklift({"key_presence": True, "seat_presence": True, "hand_brake": False, "drive": 1, "wheels_direction": 0, "forks": 0, "water_temp": 90, "oil_temp": 90, "battery": 80})
    time.sleep(5)

    # Tourner à droite
    print("Simulation : Tourner à droite")
    control_forklift({"key_presence": True, "seat_presence": True, "hand_brake": False, "drive": 1, "wheels_direction": 1, "forks": 0, "water_temp": 90, "oil_temp": 90, "battery": 80})
    time.sleep(5)

    # Tourner à gauche
    print("Simulation : Tourner à gauche")
    control_forklift({"key_presence": True, "seat_presence": True, "hand_brake": False, "drive": 1, "wheels_direction": 2, "forks": 0, "water_temp": 90, "oil_temp": 90, "battery": 80})
    time.sleep(5)

    # drive arrière
    print("Simulation : drive arrière")
    control_forklift({"key_presence": True, "seat_presence": True, "hand_brake": False, "drive": 2, "wheels_direction": 0, "forks": 0, "water_temp": 90, "oil_temp": 90, "battery": 80})
    time.sleep(8)

    # Lever les fourches
    print("Simulation : Lever les fourches")
    control_forklift({"key_presence": True, "seat_presence": True, "hand_brake": False, "drive": 0, "wheels_direction": 0, "forks": 2, "water_temp": 90, "oil_temp": 90, "battery": 80})
    time.sleep(3)

    # Baisser les fourches
    print("Simulation : Baisser les fourches")
    control_forklift({"key_presence": True, "seat_presence": True, "hand_brake": False, "drive": 0, "wheels_direction": 0, "forks": 1, "water_temp": 90, "oil_temp": 90, "battery": 80})
    time.sleep(3)

    # Simuler un excès de température
    print("Simulation : Excès de température")
    control_forklift({"key_presence": True, "seat_presence": True, "hand_brake": False, "drive": 0, "wheels_direction": 0, "forks": 0, "water_temp": 110, "oil_temp": 120, "battery": 80})
    time.sleep(2)

    # Simuler une chute de tension de battery
    print("Simulation : battery à 0%")
    control_forklift({"key_presence": True, "seat_presence": True, "hand_brake": False, "drive": 0, "wheels_direction": 0, "forks": 0, "water_temp": 90, "oil_temp": 90, "battery": 0})

if __name__ == "__main__":
    time.sleep(7)
    init_sequence()
    simulate_cmd_sequence()