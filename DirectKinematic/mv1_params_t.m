classdef mv1_params_t < handle
    properties
        r,
        h1, h2, H,
        a, h_d;
    end
    
    properties
        h, theta
    end
    
    methods
        function set (prms, name_param, value)
            switch name_param
                case 'r'
                    prms.r   = value;
                case 'h1'
                    prms.h1  = value;
                case 'h2'
                    prms.h2  = value;
                case 'H'
                    prms.H   = value;
                case 'a'
                    prms.a   = value;
                case 'h_d'
                    prms.h_d = value;
                otherwise
                    error_str = strcat ('Incorrect name param: ', name_param);
                    error (error_str);
            end
        end
        
        function value = get (prms, name_param)
            switch name_param
                case 'r'
                    value = prms.r;
                case 'h1'
                    value = prms.h1;
                case 'h2'
                    value = prms.h2;
                case 'H'
                    value = prms.H;
                case 'a'
                    value = prms.a;
                case 'h_d'
                    value = prms.h_d;
                otherwise
                    error_str = strcat ('Incorrect name param: ', name_param);
                    error (error_str);
            end
        end
        
        function calc_theta (mv1_params)
            mv1_params.theta = acos (mv1_params.h_d / mv1_params.a);
        end
        
        function calc_h (prms)
            prms.h = sqrt (prms.a ^ 2 - prms.h_d ^ 2);
        end
        
        function calc_inner_params (prms)
            prms.calc_theta ();
            prms.calc_h ();
        end
        
        function verify (mv1_params)
            if  isnumeric (mv1_params.r)  && ...
                isnumeric (mv1_params.h1) && isnumeric (mv1_params.h2)  && ...
                isnumeric (mv1_params.a)  && isnumeric (mv1_params.H)   && ...
                isnumeric (mv1_params.h)  && isnumeric (mv1_params.h_d)
                
                return;
            end

            error ('mv1 params: error verificator');
        end
        
        function Z = calc_Z (prms, phi)
            Z = prms.r ^ 2 - 2 * prms.r * prms.h1 * cos (phi) + prms.h1 ^ 2;
        end

        function L = calc_L (prms, phi)
            L = prms.h1 * ((prms.r ^ 2) * (2 + cos (2 * phi)) + prms.a ^ 2 + prms.h1 ^ 2 - prms.h2 ^ 2) + ...
                prms.r * cos (phi) * (prms.h2 ^ 2 - 3 * prms.h1 ^ 2 - prms.a ^ 2 - prms.r ^ 2);
        end
        
        function S = calc_S (prms, phi, A, B)
            S = prms.r * sin (phi) * sqrt ((2 * B * prms.h2 ^ 2 - A - prms.h2 ^ 4));
        end
        
        function A = calc_A (prms, phi)
            A = (prms.r ^ 2 - prms.a ^ 2 - 2 * prms.r * prms.h1 * cos (phi) + prms.h1 ^ 2) ^ 2;
        end

        function B = calc_B (prms, phi)
            B = prms.a ^ 2 + prms.r ^ 2 - 2 * prms.r * prms.h1 * cos (phi) + prms.h1 ^ 2;
        end

        function B_rel = calc_B_rel (prms, phi, S)
            B_rel = S * (prms.r * cos (phi) - prms.h1) / sin (phi);
        end

        function D_rel = calc_D_rel (prms, phi, B)
            D_rel = prms.r ^ 2 * sin (phi) * (B - prms.h2 ^ 2);
        end
        
        function [x_rel, z_rel] = calc_rel_point (prms, phi)
            A = calc_A (prms, phi);
            B = calc_B (prms, phi);
            S = calc_S (prms, phi, A, B);
           
            B_rel = calc_B_rel (prms, phi, S);
            D_rel = calc_D_rel (prms, phi, B);
            
            L = calc_L (prms, phi);
            Z = calc_Z (prms, phi);

            x_rel = -(D_rel + B_rel) / (2 * prms.r * Z);
            z_rel = +(L + S) / (2 * Z);
        end
        
        function point = calc_end_point (prms, phi1, phi2)
            phi = phi2 - phi1;
            prms.calc_inner_params ();
            
            [x_rel, z_rel] = calc_rel_point (prms, phi);
            
            R_phi1  = matrixRotate (phi1);
            R_theta = matrixRotate (prms.theta);
            
            p1 = [-sin(phi1); cos(phi1)] * prms.h1;
            
            point = p1 + (R_theta * prms.H / prms.a - eye (2))* R_phi1 * [x_rel; z_rel];
        end
    end
end