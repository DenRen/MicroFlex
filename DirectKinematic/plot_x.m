clc
clear

mv1_params;

phi_arr = 0:0.5:90;
x = phi_arr;
y = phi_arr;

size_arr = size (phi_arr, 2);

for i = 1:size_arr
    v = params.calc_end_point (deg2rad (-phi_arr(i)), deg2rad (90));
    x(i) = v(1);
    y(i) = v(2);
end

plot (phi_arr, x, phi_arr, y);

