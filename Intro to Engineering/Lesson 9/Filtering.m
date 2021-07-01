load -ASCII sig_n(1).mat
%loads file
sig_data = sig_n_1_;
clear sig_n_1_;
%uses a better variable name
x_label = 1/360:1/360:10;
plot(x_label,sig_data);
filter_sig = movmean(sig_data,5);
plot(x_label,filter_sig);