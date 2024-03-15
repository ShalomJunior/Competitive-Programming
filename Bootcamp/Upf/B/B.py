def f(s, old, new):
    s = s.replace(old, new)
    return s


def main():
    s = input()
    exp = ['*', '-', '+']
    for i in range(0, len(s)-1):
        if s[i] in exp and s[i+1] in exp:
            print("invalide")
            return
    s = f(s, '[', '(')
    s = f(s, ']', ')')
    s = f(s, '{', '(')
    s = f(s, '}', ')')
    s = f(s, 'x', '1')
    s = f(s, 'y', '1')
    s = f(s, 'z', '1')
    print(s)
    try:
        eval(s)
        print("valide")
    except:
        print("invalide")


if __name__ == '__main__':
    main()
