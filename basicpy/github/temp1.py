def alternate(word):    
    result=" "
    for i, character in enumerate(word):
        if i%2==0:
            result += character.upper()
        else:
            result += character.lower()
    return result


 