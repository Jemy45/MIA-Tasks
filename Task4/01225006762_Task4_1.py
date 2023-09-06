import random
# Define Villain ( initial energy and health and shield)
class Villain:
    def __init__(self, name, health=100, energy=500, shield=0):
        self.name = name
        self.health = health
        self.energy = energy
        self.shield = shield
#Effect of damage on health with respect to shield damage reduction
    def take_damage(self, damage):
        actual_damage = max(0, damage - float(damage * self.shield)) 
        self.health -= actual_damage

    def use_shield(self, shield_value):
        self.shield = shield_value

    def __str__(self):
        return f"{self.name} - Health: {self.health}, Energy: {self.energy}, Shield: {self.shield:.2f}"
#Define weapon (Energy and its damage)
class Weapon:
    def __init__(self, name, energy_cost, damage):
        self.name = name
        self.energy_cost = energy_cost
        self.damage = damage
# Using of weapon and calculating its damage and energy cost
    def use(self, villain, target):
        if villain.energy >= self.energy_cost:
            villain.energy -= self.energy_cost
            target.take_damage(self.damage)
        else:
            print(f"{villain.name} doesn't have enough energy to use {self.name}")
 #Define shield (Energy cost and save percentage)
class Shield:
    def __init__(self, name, energy_cost, save_percentage):
        self.name = name
        self.energy_cost = energy_cost
        self.save_percentage = save_percentage
 #using of shield and calculating its energy cost and damage reduction
    def use(self, villain):
        if villain.energy >= self.energy_cost:
            villain.energy -= self.energy_cost
            villain.use_shield(self.save_percentage)
        else:
            print(f"{villain.name} doesn't have enough energy to use {self.name}")
#Gru's Gadget
def choose_gru_weapon_or_shield():
    options = [
        ("Weapon", Weapon("Freeze Gun", 50, 11)),
        ("Weapon", Weapon("Electric Prod", 88, 18)),
        ("Weapon", Weapon("Mega Magnet", 92, 10)),
        ("Weapon", Weapon("Kalman Missile", 120, 20)),
        ("Shield", Shield("Energy-Projected BarrierGun", 20, 0.4)),
        ("Shield", Shield("Selective Permeability", 50, 0.9)),
    ]
    
    print("Choose Gru's action:")
    for index, (action, item) in enumerate(options, start=1):
        print(f"{index}. {action}: {item.name}")
    choice = int(input("Enter the number of your choice: ")) - 1

    action, selected_item = options[choice]
    return action, selected_item
#Vector's Gadgets
def choose_vector_weapon_or_shield():
    options = [
        ("Weapon", Weapon("Laser Blasters", 40, 8)),
        ("Weapon", Weapon("Plasma Grenades", 56, 13)),
        ("Weapon", Weapon("Sonic Resonance Cannon", 100, 22)),
        ("Shield", Shield("Energy Net Trap", 15, 0.32)),
        ("Shield", Shield("Quantum Deflector", 40, 0.8)),
    ]
      #Randomly choosing 1 of them
    return random.choice(options)

def simulate_round(villain1, villain2):
    gru_action, gru_item = choose_gru_weapon_or_shield()
    vector_action, vector_item = choose_vector_weapon_or_shield()

    if gru_action == "Weapon":
        gru_item.use(villain1, villain2)
    else:
        gru_item.use(villain1)
    
    if vector_action == "Weapon":
        vector_item.use(villain2, villain1)
    else:
        vector_item.use(villain2)

    print(villain1)
    print(villain2)

# Defining our 2 Villains
gru = Villain("Gru")
vector = Villain("Vector")

# Simulate rounds untill health of some one be 0
round_number = 1
while gru.health > 0 and vector.health > 0:
    print(f"Round {round_number}")
    simulate_round(gru, vector)
    round_number += 1

# Determine the winner
if gru.health <= 0:
    print("Vector wins!")
else:
    print("Gru wins!")
