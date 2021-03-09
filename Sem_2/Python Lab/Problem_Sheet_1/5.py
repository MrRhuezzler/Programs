# Write a program for computing the product cost. The program should
# get the number of items and the price per item. The output should
# show computed cost in a neat format.

items = []
while True:
    item = {}
    item['name'] = input('Product Name : ')
    item['cost'] = float(input('Price of the item : '))
    item['qty'] = int(input('Quantity : '))
    item['total'] = item['cost'] * item['qty']
    items.append(item)

    choice = input('Do you want to add more \n y/n (y) : ')
    if(choice == 'n'):
        break

print(f"{'S.No' : ^12}|{'Name' : ^12}|{'Cost' : ^12}|{'Qty' : ^12}|{'Total':^12}")
totalCost = 0
for index, item in enumerate(items):
    print(f"{index+1 : ^12}|{item['name'] : ^12}|{item['cost'] : ^12}|{item['qty'] : ^12}|{item['total']:^12}")
    totalCost += item['total']
print(f"Grand Amount : {totalCost}")
