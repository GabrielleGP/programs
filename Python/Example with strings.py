def siruri():
    s1=input("Enter first string:")
    s2=input("Enter second string:")
    print("First string: "+s1)
    print("Second string: "+s2)
    part1=s1[0:len(s1)//2]
    print("First part of the first string: "+part1)
    from collections import Counter
    dict1 = Counter(part1)
    dict2 = Counter(s2)
    commonDict = dict1 & dict2
    if len(commonDict) == 0:
        print -1
        return
    commonChars = list(commonDict.elements())
    import itertools
    print("The final list: ")
    print(list(itertools.chain.from_iterable(itertools.repeat(x, 2) for x in commonChars)))
