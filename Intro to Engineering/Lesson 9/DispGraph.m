function DispGraph(x,y,grid,TitleMod)
%Plots the Surface and then the Contour for PeaksMatLab

%Surface
name = ['Surface of elevations.txt, ', TitleMod];
%Gives a proper title, for style.
figure('Name',name,'NumberTitle','Off');
%name the figure
surf(x,y,grid);
title(name);

%Contour
name = ['Contour of elevations.txt, ', TitleMod];
figure('Name',name,'NumberTitle','Off');
%starts a new figure
contour(x,y,grid,30); %30 for more accurate peak determining
title(name);
end

