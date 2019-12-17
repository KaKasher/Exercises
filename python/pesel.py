def isPeselValid(pesel):
    try:
        val = int(pesel)
    except ValueError:
        return False

    if len(pesel) != 11:
        return False
        
    pesel = list(map(int, pesel))
    
    controlSum = 9*pesel[0] + 7*pesel[1] + 3*pesel[2] + 1*pesel[3] + 9*pesel[4] + 7*pesel[5] + 3*pesel[6] + 1*pesel[7] + 9*pesel[8] + 7*pesel[9]
    
    if controlSum % 10 != pesel[10]:
        return False
        
    return True
    
def calculateDecade(decadeCode):
    return {
        0 : 19,
        20 : 20,
        40 : 21,
        60 : 22,
        80 : 18
    }[decadeCode]
    
def calculateDate(pesel):
    day = pesel[3:5]
    month = int(pesel[2:4])
    decadeCode = 0;

    while month not in range(1, 12):
        month -= 20
        decadeCode =+ 20
        
    year = str(calculateDecade(decadeCode)) + pesel[:2]
    
    return '.'.join([day, str(month), year])

def calculateGender(pesel):
    if int(pesel[-2]) % 2 == 0:
        return "Kobieta"
    else:
        return "Mezczyzna"

# Main Loop
while True:
    pesel = input("Wpisz pesel: ")
   
    if isPeselValid(pesel) == False:
        print("Podany PESEL jest nie poprawny")
        continue
        
    date = calculateDate(pesel)
    gender = calculateGender(pesel)

    print(date, gender)
    