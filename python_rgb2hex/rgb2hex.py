r, g, b = map(int, input("Values for r/g/b, comma-separated: ").split(","))

rh = hex(r)
gh = hex(g)
bh = hex(b)
col_str = f"#{str(rh)[2:].zfill(2)}{str(gh)[2:].zfill(2)}{str(bh)[2:].zfill(2)}"

print(col_str)

