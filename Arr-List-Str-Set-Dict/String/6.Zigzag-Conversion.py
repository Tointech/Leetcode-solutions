# numRows = 4
# P           I         N
# A      L    S     I   G
# Y    A      H    R
# P           I
#
# P  A  Y  P  A  L  I  S  H  I  R  I  N  G
# -----------------------------------------
# 1  2  3  4  3  2  1  2  3  4  3  2  1  2

# numRows = 3
# P         A         H         N
# A    P    L    S    I    I    G
# Y         I         R
#
# P  A  Y  P  A  L  I  S  H  I  R  I  N  G
# -----------------------------------------
# 1  2  3  2  1  2  3  2  1  2  3  2  1  2

class Solution:
    def convert(self, s:str, numRows:int) -> str:
        if numRows == 1:
            return s
        
        row_arr = [""] * numRows
        row_idx = 1
        increase = True

        for char in s:
            row_arr[row_idx-1] += char

            if row_idx == numRows:
                increase = False
            elif row_idx == 1:
                increase = True

            if increase:
                row_idx += 1
            else:
                row_idx -= 1
        
        return "".join(row_arr)



if __name__ == "__main__":
    sol = Solution()
    s = "PAYPALISHIRING"
    numRows = 4 

    result = sol.convert(s, numRows)
    # ['P', '', '', '']
    # ['P', 'A', '', '']
    # ['P', 'A', 'Y', '']
    # ['P', 'A', 'Y', 'P']
    # ['P', 'A', 'YA', 'P']
    # ['P', 'AL', 'YA', 'P']
    # ['PI', 'AL', 'YA', 'P']
    # ['PI', 'ALS', 'YA', 'P']
    # ['PI', 'ALS', 'YAH', 'P']
    # ['PI', 'ALS', 'YAH', 'PI']
    # ['PI', 'ALS', 'YAHR', 'PI']
    # ['PI', 'ALSI', 'YAHR', 'PI']
    # ['PIN', 'ALSI', 'YAHR', 'PI']
    # ['PIN', 'ALSIG', 'YAHR', 'PI']
    # ['PIN', 'ALSIG', 'YAHR', 'PI'] -> PINALSIGYAHRPI
    print(result)
