classdef mv1_params_t < handle
    properties
        r,
        h1, h2, H,
        h, h_d;
    end
    
    properties
        a, theta
    end
    
    methods
        function set (prms, name_param, value)
            switch name_param
                case 'r'
                    prms.r = value;
                case 'h1'
                    prms.h1 = value;
                case 'h2'
                    prms.h2 = value;
                case 'H'
                    prms.H = value;
                case 'h'
                    prms.h = value;
                case 'h_d'
                    prms.h_d = value;
                otherwise
                    error 'Incorrect name param'
            end
        end
        
        function calc_theta (mv1_params)
            mv1_params.theta = atan (mv1_params.h / mv1_params.h_d);
        end
        
        function calc_a (mv1_params)
            mv1_params.a = sqrt (mv1_params.h_d ^ 2 + mv1_params.h ^ 2);
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
            S = sqrt ((prms.r * sin (phi)) ^ 2 * (2 * B * prms.h2 ^ 2 - A - prms.h2 ^ 4));
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

            x_rel = (D_rel + B_rel) / (2 * prms.r * Z);
            z_rel = (L + S) / (2 * Z);
        end

        function point = calc_end_point (prms, phi1, phi2)
            phi = phi2 - phi1;
            prms.calc_a ();
            
            [x_rel, z_rel] = calc_rel_point (prms, phi);
            
            prms.calc_theta ();
            theta = prms.theta;
            
            R_phi = [cos(theta), -sin(theta); sin(theta), cos(theta)];
            R_tht = [cos(theta), sin(theta); -sin(theta), cos(theta)];
            
            p1 = [sin(phi1); cos(phi1)] * prms.h;
            
            point = p1 + prms.H / prms.a * R_tht * R_phi * [x_rel; z_rel];
        end
    end
end