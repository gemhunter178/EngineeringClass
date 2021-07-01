function [year_data] = extractdata(datestart, dateend, year_matrix, target_matrix)
%Extracts a certain year's data
startdate = find(year_matrix == datenum(datestart, 'yyyymmdd'));
enddate = find(year_matrix == datenum(dateend, 'yyyymmdd'));
%converts input start and end dates start and end indeces
year_data = target_matrix(startdate:enddate);
end

