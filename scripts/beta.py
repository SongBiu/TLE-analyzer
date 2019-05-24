def alpha(mean, std):
    return mean - std, mean + std

def beta(alpha_tle, alpha_ac):
    tle_min = alpha_tle[0]
    tle_max = alpha_tle[1]

    ac_min = alpha_ac[0]
    ac_max = alpha_ac[1]

    if tle_min > ac_max or tle_max < ac_min:
        return 0
    cap_len = min(ac_max, tle_max) - max(ac_min, tle_min)
    return cap_len * 1.0 / (tle_max - tle_min), cap_len * 1.0 / (ac_max - ac_min)

def cal(tle_mean, tle_std, ac_mean, ac_std):
    return beta(alpha(tle_mean, tle_std), alpha(ac_mean, ac_std))