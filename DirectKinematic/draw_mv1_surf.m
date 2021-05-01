function draw_mv1_surf (params, surf_axes_x, surf_axes_z)
    params.verify ();

    phi1_arr = -pi/2:0.1:pi/2;
    phi2_arr = phi1_arr;

    phi1_arr_size = size (phi1_arr, 2);
    phi2_arr_size = size (phi2_arr, 2);

    points_x = zeros (phi1_arr_size, phi2_arr_size);
    points_z = zeros (phi1_arr_size, phi2_arr_size);

    for i = 1:phi1_arr_size
        for j = 1:phi2_arr_size
            p = params.calc_end_point (phi1_arr(i), phi2_arr(j));
            points_x(i, j) = p(1);
            points_z(i, j) = p(2);
        end
    end

    surf (surf_axes_x, phi1_arr, phi2_arr, points_x);
    surf (surf_axes_z, phi1_arr, phi2_arr, points_z);
end