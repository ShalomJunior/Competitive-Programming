def rep(s, l, n):
    for c in l:
        s = s.replace(c, n)
    return s


def mod(s):
    l = ['[', '{']
    s = rep(s, l, '(')

    l = [']', '}']
    s = rep(s, l, ')')

    l = ['x', 'y', 'z']
    s = rep(s, l, '0')

    return s


def is_op(c):
    return (c == '+' or c == '-' or c == '*')


def main():
    s = input()

    for i in range(0, len(s)-1):
        if is_op(s[i]) and is_op(s[i+1]):
            print("invalide")
            return

    s = mod(s)
    try:
        eval(s)
        print("valide")
    except:
        print("invalide")


if __name__ == '__main__':
    main()
