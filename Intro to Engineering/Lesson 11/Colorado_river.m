openFile = fopen('Colorado_Discharge_UT_CO.txt');
Discharge = textscan(openFile, '%s%d%s%f%s', 'headerlines', 30);
fclose(openFile);
[~,~,date,discharge,~] = Discharge{:};
clear Discharge;
%All of this reads and clears things I don't need. 
daten = datenum(date(:),'yyyy-mm-dd');
%converts date to a number

y1955 = extractdata('19550101','19551231',daten,discharge);
y1960 = extractdata('19600101','19601230',daten,discharge);
y1965 = extractdata('19650101','19651231',daten,discharge);
y1970 = extractdata('19700101','19701231',daten,discharge);
y1975 = extractdata('19750101','19751231',daten,discharge);
y1980 = extractdata('19800101','19801230',daten,discharge);
y1985 = extractdata('19850101','19851231',daten,discharge);
y1990 = extractdata('19900101','19901231',daten,discharge);
y1995 = extractdata('19950101','19951231',daten,discharge);
y2000 = extractdata('20000101','20001230',daten,discharge);
y2005 = extractdata('20050101','20051231',daten,discharge);
y2010 = extractdata('20100101','20101231',daten,discharge);
y2015 = extractdata('20150101','20151231',daten,discharge);
%Extracts all the discharge rates for the years indicated
%the end dates that end in '-1230' are leap years. The last day is excluded

year = 1955:5:2015;
day = 1:365;
%gives a year and a day
year_array = [y1955, y1960, y1965, y1970, y1975, y1980, y1985, y1990, y1995, y2000, y2005, y2010, y2015]';
%makes an array for the years

figure('Name',"Discharge Relative to Year and Date (Surface)",'NumberTitle','Off');
surf(day,year,year_array);
title("Discharge Relative to Year and Date (Surface)");
xlabel("Day of the year");
ylabel("Year");
zlabel("Average output (ft^3/s)");
%{
figure('Name',"Discharge Relative to Year and Date (Contour)",'NumberTitle','Off');
contour(day,year,year_array,15);
xlabel("Day of the year");
ylabel("Year");
%}
%These are all for graphing and such

y1955 = cumtrapz(y1955)*24*60*60;
y1960 = cumtrapz(y1960)*24*60*60;
y1965 = cumtrapz(y1965)*24*60*60;
y1970 = cumtrapz(y1970)*24*60*60;
y1975 = cumtrapz(y1975)*24*60*60;
y1980 = cumtrapz(y1980)*24*60*60;
y1985 = cumtrapz(y1985)*24*60*60;
y1990 = cumtrapz(y1990)*24*60*60;
y1995 = cumtrapz(y1995)*24*60*60;
y2000 = cumtrapz(y2000)*24*60*60;
y2005 = cumtrapz(y2005)*24*60*60;
y2010 = cumtrapz(y2010)*24*60*60;
y2015 = cumtrapz(y2015)*24*60*60;
%for the total ft^3 outputted in an year

totDischarge_array = [y1955, y1960, y1965, y1970, y1975, y1980, y1985, y1990, y1995, y2000, y2005, y2010, y2015];
%makes it an array
clear y1995 y1960 y1965 y1970 y1975 y1980 y1985 y1990 y1995 y2000 y2005 y2010 y2015
%clears individucal extracted years

figure('Name',"Colorado River Discharge Per Year at UT-CO Border",'NumberTitle','Off');
plot(year,totDischarge_array(365,:));
title("Colorado River Discharge Per Year at UT-CO Border");
xlabel("year");
ylabel("Total Discharge, ft^3");
%plots the discharge rate per years extracted
hold on;
best_fit = polyfit(year,totDischarge_array(365,:),1);
plot(year,polyval(best_fit,year));
%keeps the previous graph and layers a line of best fit on top of it.
legend("Total Discharge","Trend (Linear)");
%makes a legend

%{
%%OLDER REMAINANTS
plot(discharge);
x = cumtrapz(discharge);
figure('Name',"Discharge since start of data",'NumberTitle','Off');
plot(daten,x);
datetick('x','keepticks','keeplimits');
%}