input_file = "arabi.txt"
output_file = "output.txt"

def solution(word):
    result=" "
    for i, character in enumerate(word):
        if i%2==0:
            result += character.upper()
        else:
            result += character.lower()
    return result

def main():
    with open(input_file, "r") as input:
        with open(output_file, "w") as output:
            for line in input:
                s=solution(line)
                output.write(str(s)+'\n') #"".join(s)

if __name__=="__main__":
    main()
    