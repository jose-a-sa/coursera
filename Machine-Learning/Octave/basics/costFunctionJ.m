function J = costFunctionJ(X, y, th)

m = size(X, 1);
pred = X*th;
sqErr = (pred - y).^2;

J = 1/(2*m) * sum(sqErr)