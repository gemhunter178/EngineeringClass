function distoutput = distance2D(n_start_loc, n_end_loc, w_start_loc, w_end_loc)
    n_diff = n_start_loc - n_end_loc;
    w_diff = w_start_loc - w_end_loc;
    distoutput = sqrt(n_diff^2 + w_diff^2);
end

