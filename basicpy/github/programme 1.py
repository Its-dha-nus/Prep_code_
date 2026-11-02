def alternate(s):
    result=" "
    for i, character in enumerate(s):
        if i%2==0:
            result += character.upper()
        else:
            result += character.lower()
    return result
s=(input("EnTeR A WoRd oR SeNtEnCe tO MaKe iT LiKe tHiS : "))
print(alternate(s))

 