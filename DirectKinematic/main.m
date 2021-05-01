clc;
clear;

mv1_params;

steps_vars = 1;
koef_var = 0.01;

str_vars = ["r" "h1" "h2" "H" "a" "h_d"];
num_str_vars = size (str_vars, 2);

for j = 1:num_str_vars
    val = params.get (str_vars(j));
    str_vars(j)
    for i = -1:steps_vars
        params.set (str_vars(j), val * (1 + i * koef_var));
        params.calc_end_point (deg2rad (0), deg2rad (-90));
    end
    
    params.set (str_vars(j), val);
end

params.calc_end_point (deg2rad (0), deg2rad (-45));