hex_color = str(input("Hex color string (without leading #): "))

hr = hex_color[0:2]
hg = hex_color[2:4]
hb = hex_color[4:6]
col_str = f"{int(hr, 16)},{int(hg, 16)},{int(hb, 16)}"

print(col_str)
