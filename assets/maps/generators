from random import randint
import sys

def generate_line():
    first_number = randint(1, 1920)
    second_number = randint(1, 1080)
    third_number = randint(1, 1920)
    fourth_number = randint(1, 1080)
    last_number = randint(1, 99)
    return f"A {first_number} {second_number} {third_number} {fourth_number} {last_number} 0"

def generate_tower():
    first_number = randint(1, 1920)
    second_number = randint(1, 1080)
    last_number = randint(1, 99)

    return f"T {first_number} {second_number} {last_number}"

def readme():
    print("USAGE")
    print("     python3 -p -t > file.txt")
    print("DESCRIPTION")
    print("     -p numbers of planes\n     -t numbers of tower")
    print("Nicolas >>>>")
    return 0

def main(argv):
    if (len(argv) == 1):
        return readme()
    lines = [generate_line() for _ in range(int(argv[1]))]
    tower = [generate_tower() for _ in range(int(argv[2]))]

    for line in lines:
        print(line)
    for line in tower:
        print(line)

if __name__ == "__main__":
    main(sys.argv)