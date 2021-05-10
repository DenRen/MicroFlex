function draw_mv1_surf (params, surf_axes_x, surf_axes_z)
    params.verify ();

    phi0_arr = -pi/2:0.1:pi/2;
    phi1_arr = phi0_arr;

    phi0_arr_size = size (phi0_arr, 2);
    phi1_arr_size = size (phi1_arr, 2);

    points_x = zeros (phi0_arr_size, phi1_arr_size);
    points_z = zeros (phi0_arr_size, phi1_arr_size);

    for i = 1:phi0_arr_size
        for j = 1:phi1_arr_size
            p = params.calc_end_point (phi0_arr(i), phi1_arr(j), 0);
            points_x(i, j) = p(1);
            points_z(i, j) = p(2);
        end
    end

    surf (surf_axes_x, phi0_arr, phi1_arr, points_x);    
    surf (surf_axes_z, phi0_arr, phi1_arr, points_z);
end