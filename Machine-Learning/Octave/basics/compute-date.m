load('week2/featuresX.dat')
load('week2/priceY.dat')

A = [1 2; 3 4; 5 6]
B = [11 12; 13 14; 15 16]
C = [1 1; 2 2]

A * C % dot matrix multiplication
A .* B % element multiplication
A .^ 2 % element power

v = [1; 2; 3]
1 ./ v % element division
1 ./ A

log(v) % element map
-v

v + ones(length(v), 1)
v + 1

A
A' % transpose

a = [1 15 2 0.5]
val = max(a)
[val, ind] = max(a)

find(a < 3)

A = magic(3)

[r, c] = find(A >= 7);
[r c]

sum(a)
prod(a)

floor(a)
ceil(a)

max(rand(3,3), rand(3,3))

max(A, [], 1)
max(A, [], 2)

A = magic(9)

sum(A, 1)
sum(A, 2)

sum((A .* eye(9))(:))

flipud(eye(9))

A = magic(3)

pinv(A) * A
A * pinv(A)
