load('week2/featuresX.dat')
load('week2/priceY.dat')
whos
v = priceY(1:10)
save 'week2/dataV.dat' v -ascii 


A = [1 2; 3 4; 5 6]
A(3,2)
A(2,:)
A(2,:)
A([1 3], :)
A(:,2) = [10; 11; 12]
% append
A = [A, [100; 101; 102]]
% flatten
A(:)
