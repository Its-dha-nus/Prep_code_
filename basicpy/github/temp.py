input_file = "test.txt"
output_file = "testoutputfile"

def solution(word):
    return word[::-1] 

def main():
    with open(input_file, "r") as input:
        with open(output_file, "w") as output:
            for line in input:
                s=solution(line)
                output.write(str(s)+'\n')
                             

if __name__=="__main__":
    main()
