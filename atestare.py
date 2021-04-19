def siruri():
    s1=input("introduceti 1 sir: ")
    s2=input("Introduceti al 2-lea sir: ")
    print("Sirul 1: "+s1)
    print("Sirul 2: "+s2)
    part1=s1[0:len(s1)//2]
    print("Prima parte 1 sir: "+part1)
    from collections import Counter
    dict1 = Counter(part1)
    dict2 = Counter(s2)
    commonDict = dict1 & dict2
    if len(commonDict) == 0:
        print -1
        return
    commonChars = list(commonDict.elements())
    import itertools
    print("Lista finala: ")
    print(list(itertools.chain.from_iterable(itertools.repeat(x, 2) for x in commonChars)))
