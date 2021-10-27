n, k = [int(i) for i in str(input()).split(" ")]

qy, qx = [int(i) for i in str(input()).split(" ")]

# h_line = X - qx
# v_line = Y - qy
# p_diagnal = Y - X - (qy - qx)
# n_diagnol = Y + X - (qy + qx)


def cal_not_possible_attack_on_h_line(h_line_points_x, p):
    not_possible_attack = 0

    if len(h_line_points_x) > 0:
        min_x_h_point = min(h_line_points_x)
        max_x_h_point = max(h_line_points_x)

        # print("min_x_h_point: ", min_x_h_point)

        #print("max_x_h_point: ", max_x_h_point)
        if min_x_h_point > p:
            not_possible_attack += (n - min_x_h_point + 1)

        elif max_x_h_point < p:
            not_possible_attack += (max_x_h_point)

        elif min_x_h_point < p and max_x_h_point > p:
            not_possible_attack += (min_x_h_point + n - max_x_h_point + 1)

    return not_possible_attack


def cal_not_possible_attack_on_v_line(v_line_points_y, q):
    not_possible_attack = 0

    if len(v_line_points_y) > 0:
        min_y_v_point = min(v_line_points_y)
        max_y_v_point = max(v_line_points_y)

        # print("min_y_v_point: ", min_y_v_point)

        #print("max_y_v_point: ", max_y_v_point)
        if min_y_v_point > q:
            not_possible_attack += (n - min_y_v_point + 1)

        elif max_y_v_point < q:
            not_possible_attack += (max_y_v_point)

        elif min_y_v_point < q and max_y_v_point > q:
            not_possible_attack += (min_y_v_point + n - max_y_v_point + 1)

    return not_possible_attack


def cal_not_possible_attack_on_p_diagonal_bottom(p_diagonal_points_x_bottom,
                                                 p_diagonal_points_y_bottom):
    not_possible_attack = 0
    
    if len(p_diagonal_points_y_bottom) > 0:
        y = max(p_diagonal_points_y_bottom)
        x = p_diagonal_points_x_bottom[p_diagonal_points_y_bottom.index(y)]
        not_possible_attack += min([x, y])

    return not_possible_attack


def cal_not_possible_attack_on_p_diagonal_top(p_diagonal_points_x_top,
                                              p_diagonal_points_y_top):
    not_possible_attack = 0

    if len(p_diagonal_points_y_top) > 0:
        y = min(p_diagonal_points_y_top)
        x = p_diagonal_points_x_top[p_diagonal_points_y_top.index(y)]
        not_possible_attack += min([n - x + 1, n - y +1])

    return not_possible_attack


def cal_not_possible_attack_on_n_diagonal_bottom(n_diagonal_points_x_bottom,
                                                 n_diagonal_points_y_bottom):
    not_possible_attack = 0

    if len(n_diagonal_points_y_bottom) > 0:
        y = max(n_diagonal_points_y_bottom)
        x = n_diagonal_points_x_bottom[n_diagonal_points_y_bottom.index(y)]

        not_possible_attack += min(n - x + 1, y)

    return not_possible_attack


def cal_not_possible_attack_on_n_diagonal_top(n_diagonal_points_x_top,
                                              n_diagonal_points_y_top):
    not_possible_attack = 0

    if len(n_diagonal_points_y_top) > 0:
        y = min(n_diagonal_points_y_top)
        x = n_diagonal_points_x_top[n_diagonal_points_y_top.index(y)]

        not_possible_attack += min(n - y + 1, x)

    return not_possible_attack


def queen_attack_all_possible():
    total_point_on_h_line = n - 1  #(qx - 1) + (n - qx)
    total_point_on_v_line = n - 1  #(qy - 1) + (n - qy)

    total_point_on_p_diagnol = min([qx - 1, qy - 1]) + min([n - qx, n - qy])
    total_point_on_n_diagnol = min([n - qx, qy - 1]) + min([qx - 1, n - qy])
    print(total_point_on_h_line, total_point_on_v_line,
          total_point_on_p_diagnol, total_point_on_n_diagnol)
    return total_point_on_h_line + total_point_on_v_line + total_point_on_p_diagnol + total_point_on_n_diagnol


def queen_attack_not_possible():
    h_line_points_x = []
    h_line_points_y = []

    v_line_points_x = []
    v_line_points_y = []

    p_diagonal_points_x_bottom = []
    p_diagonal_points_y_bottom = []
    p_diagonal_points_x_top = []
    p_diagonal_points_y_top = []

    n_diagonal_points_x_top = []
    n_diagonal_points_x_bottom = []
    n_diagonal_points_y_top = []
    n_diagonal_points_y_bottom = []
    for _ in range(0, k):
        q, p = [int(val) for val in str(input()).split(" ")]

        # point lies on h_line
        #print("p - qx: " ,p - qx)
        if p - qx == 0:
            v_line_points_x.append(p)
            v_line_points_y.append(q)

        # point lies on v_line
        #print("q -qy: " ,q -qy)
        if q - qy == 0:
            h_line_points_x.append(p)
            h_line_points_y.append(q)

        # point lies on p_diagonal
        #print("q - p -(qy -qx): ", q - p -(qy -qx) )
        if q - p - (qy - qx) == 0:
            if q < qy:
                p_diagonal_points_x_bottom.append(p)
                p_diagonal_points_y_bottom.append(q)
            else:
                p_diagonal_points_x_top.append(p)
                p_diagonal_points_y_top.append(q)

        # point lies on n_diagonal
        #print("q + p -(qy + qx): ",q + p -(qy + qx) )
        if q + p - (qy + qx) == 0:
            if q < qy:
                n_diagonal_points_x_bottom.append(p)
                n_diagonal_points_y_bottom.append(q)
            else:
                n_diagonal_points_x_top.append(p)
                n_diagonal_points_y_top.append(q)

    # print("h_line_points: ", h_line_points_x, h_line_points_y)
    # print("v_line_points: ", v_line_points_x, v_line_points_y)
    # print("n_diagonal_points_bottom; ", n_diagonal_points_x_bottom,
    #       n_diagonal_points_y_bottom)
    # print("n_diagonal_points_top; ", n_diagonal_points_x_top,
    #       n_diagonal_points_y_top)
    # print("p_diagonal_points_bottom: ", p_diagonal_points_x_bottom,
    #       p_diagonal_points_y_bottom)
    # print("p_diagonal_points_top: ", p_diagonal_points_x_top,
    #       p_diagonal_points_y_top)
    # print("cal_not_possible_attack_on_h_line: ",
    #       cal_not_possible_attack_on_h_line(h_line_points_x, qx))

    # print("cal_not_possible_attack_on_v_line: ",
    #       cal_not_possible_attack_on_v_line(v_line_points_y, qy))

    # print(
    #     "cal_not_possible_attack_on_p_diagonal_bottom: ",
    #     cal_not_possible_attack_on_p_diagonal_bottom(
    #         p_diagonal_points_x_bottom, p_diagonal_points_y_bottom))

    # print(
    #     "cal_not_possible_attack_on_p_diagonal_top: ",
    #     cal_not_possible_attack_on_p_diagonal_top(p_diagonal_points_x_top,
    #                                               p_diagonal_points_y_top))

    # print(
    #     "cal_not_possible_attack_on_n_diagonal_bottom: ",
    #     cal_not_possible_attack_on_n_diagonal_bottom(
    #         n_diagonal_points_x_bottom, n_diagonal_points_y_bottom))

    # print(
    #     "cal_not_possible_attack_on_n_diagonal_top: ",
    #     cal_not_possible_attack_on_n_diagonal_top(n_diagonal_points_x_top,
    #                                               n_diagonal_points_y_top))
    return cal_not_possible_attack_on_h_line(
        h_line_points_x, qx) + cal_not_possible_attack_on_v_line(
            v_line_points_y,
            qy) + cal_not_possible_attack_on_p_diagonal_bottom(
                p_diagonal_points_x_bottom, p_diagonal_points_y_bottom
            ) + cal_not_possible_attack_on_p_diagonal_top(
                p_diagonal_points_x_top, p_diagonal_points_y_top
            ) + cal_not_possible_attack_on_n_diagonal_bottom(
                n_diagonal_points_x_bottom, n_diagonal_points_y_bottom
            ) + cal_not_possible_attack_on_n_diagonal_top(
                n_diagonal_points_x_top, n_diagonal_points_y_top)


print(queen_attack_all_possible() - queen_attack_not_possible())
#print(queen_attack_not_possible())
