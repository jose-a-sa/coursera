function [C, sigma] = dataset3Params(X, y, Xval, yval)
%DATASET3PARAMS returns your choice of C and sigma for Part 3 of the exercise
%where you select the optimal (C, sigma) learning parameters to use for SVM
%with RBF kernel
%   [C, sigma] = DATASET3PARAMS(X, y, Xval, yval) returns your choice of C and 
%   sigma. You should complete this function to return the optimal C and 
%   sigma based on a cross-validation set.
%

% You need to return the following variables correctly.
C = 1;
sigma = 0.3;

% ====================== YOUR CODE HERE ======================
% Instructions: Fill in this function to return the optimal C and sigma
%               learning parameters found using the cross validation set.
%               You can use svmPredict to predict the labels on the cross
%               validation set. For example, 
%                   predictions = svmPredict(model, Xval);
%               will return the predictions on the cross validation set.
%
%  Note: You can compute the prediction error using 
%        mean(double(predictions ~= yval))
%

C_list = [0.01, 0.03, 0.1, 0.3, 1, 3, 10, 30];
sigma_list = [0.01, 0.03, 0.1, 0.3, 1, 3, 10, 30];

errors = zeros(length(C_list),  length(sigma_list)); 

for i = 1:length(C_list)
    for j = 1:length(sigma_list)
        C0 = C_list(i);
        sigma0 = sigma_list(j);
        model = svmTrain(X, y, C0, @(x1, x2) gaussianKernel(x1, x2, sigma0));
        predictions = svmPredict(model, Xval);
        errors(i,j) = mean(double(predictions ~= yval));
    end
end

[min_error, ind] = min(errors(:));
[c, s] = ind2sub(size(errors), ind);

C = C_list(c);
sigma = sigma_list(s);


% =========================================================================

end
