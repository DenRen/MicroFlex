function sliderchanging
% Create figure window and components

fig = uifigure('Position',[100 100 350 275]);

cg = uigauge(fig,'Position',[100 100 120 120]);

sld = uislider(fig,...
               'Position',[100 75 120 3],...
               'ValueChangingFcn',@(sld,event) sliderMoving(event,cg));

end

% Create ValueChangingFcn callback
function sliderMoving(event,cg)
cg.Value = event.Value;
end

clc;
clear;
surf ();
mv1_params;

params = mv1_params ();

params.r = 2;
params.h1 = 25;
params.h2 = 23;
params.H = 26;
params.h_d = 6;
params.h = 3;

%draw_mv1_surf (params);

fig = uifigure;
pnl = uipanel(fig);
sld = uislider(pnl, 'Position',[50 50 180 3], ...
                    'Limits', [-60, pi]);