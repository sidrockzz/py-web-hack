string = str(input());

list1 = list(string);

rp = list(input().split());

list1[int(rp[0])]=rp[1];

string = ''.join(list1);

print(string)