%This is the elevations assignment for MatLab, Assignment 9.

%Start by opening the file (which I copied over to the same folder for
%easier reading
openFile = fopen('elevations.txt');
%open the file for textscan
elevData = textscan(openFile,'%f%f%f%f%f%f%f', 'headerlines', 1);
%file is now stored in a matrix of float matrices
fclose(openFile);
%close file
elevations = cell2mat(elevData);
%converts the read then written stuff to a 7x7 matrix
x = 1:7;
y = 1:7;
%for coordinates

%first graphs with the original
DispGraph(x,y,elevations,'Original');

%take the interpolations and graph them
[xMesh, yMesh] = meshgrid(1:.2:7);
%make the mesh grid
elevInter = interp2(x,y,elevations,xMesh,yMesh,'linear');
DispGraph(xMesh,yMesh,elevInter,'Linear Interpolation');
%Function was made to show surface and contour plots
%Repeat for other 4 types
%nearest
elevInter = interp2(x,y,elevations,xMesh,yMesh,'nearest');
DispGraph(xMesh,yMesh,elevInter,'Nearest Interpolation');
%cubic
elevInter = interp2(x,y,elevations,xMesh,yMesh,'cubic');
DispGraph(xMesh,yMesh,elevInter,'Cubic Interpolation');
%spline
elevInter = interp2(x,y,elevations,xMesh,yMesh,'spline');
DispGraph(xMesh,yMesh,elevInter,'Spline Interpolation');
%makima
elevInter = interp2(x,y,elevations,xMesh,yMesh,'makima');
DispGraph(xMesh,yMesh,elevInter,'Makima Interpolation');
