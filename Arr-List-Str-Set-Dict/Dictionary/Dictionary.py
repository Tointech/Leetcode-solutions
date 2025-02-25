# 1. Create a dictionary
country_capitals = {
  "Germany": "Berlin", 
  "Canada": "Ottawa", 
  "England": "London"
}
print(country_capitals)

# 2. Access Items
print(country_capitals["Germany"])
print(country_capitals.get("Canada"))

# 3. Add Items
country_capitals["Italy"] = "Rome"
print(country_capitals)

# 4. Remove Items
country_capitals.pop("Germany")
print(country_capitals)

# 5. Change Items
country_capitals["Canada"] = "Toronto"
print(country_capitals)

# 6. Iterate Over Dictionary
for country in country_capitals:
    print(country, country_capitals[country])