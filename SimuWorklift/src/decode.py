def decode_trame(hex_trame):
    if len(hex_trame) < 14:
        raise ValueError("Trame trop courte, elle doit contenir 14 caractères hexadécimaux")

    # 1er caractère hexadécimal - 4 bits booléens
    bool_data = int(hex_trame[0], 16)
    key_presence = bool(bool_data & 0x8)    # 1000
    seat_presence = bool(bool_data & 0x4)   # 0100
    hand_brake = bool(bool_data & 0x2)      # 0010
    shock = bool(bool_data & 0x1)           # 0001

    # 2e caractère hexadécimal - Marche (3 états possibles)
    drive = int(hex_trame[1], 16)
    if drive > 2:
        raise ValueError("Wrong value for Marche")

    # 3e caractère hexadécimal - Direction des roues (3 états possibles)
    wheels_direction = int(hex_trame[2], 16)
    if wheels_direction > 2:
        raise ValueError("Wrong value for Direction Roues")
        
    # 4e caractère hexadécimal - Hauteur des fourches (3 états possibles)
    forks = int(hex_trame[3], 16)
    if forks > 2:
        raise ValueError("Wrong value for hauteur fourches")

    # 5e et 6e caractères hexadécimaux - Vitesse
    speed = int(hex_trame[4:6], 16)

    # 7e et 8e caractères hexadécimaux - Température de l'eau
    water_temp = int(hex_trame[6:8], 16)

    # 9e et 10e caractères hexadécimaux - Température d'huile
    oil_temp = int(hex_trame[8:10], 16)

    # 11e et 12e caractères hexadécimaux - Batterie
    battery = int(hex_trame[10:12], 16)

    # 13e et 14e caractères hexadécimaux - Fin de trame (toujours FF)
    end_trame = hex_trame[12:14]
    if end_trame != "ff":
        raise ValueError("La trame ne se termine pas correctement par 'FF'")

    # Retourner les valeurs sous forme de dictionnaire
    return {
        "key_presence": key_presence,
        "seat_presence": seat_presence,
        "hand_brake": hand_brake,
        "shock": shock,
        "drive": drive,
        "wheels_direction": wheels_direction,
        "forks": forks,
        "speed": speed,
        "water_temp": water_temp,
        "oil_temp": oil_temp,
        "battery": battery
    }

# Exemple d'utilisation
if __name__ == "__main__":
    hex_trame = "1111567890ABFF"  # Exemple de trame en hexadécimal
    values = decode_trame(hex_trame)
    print(values)
