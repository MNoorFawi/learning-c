set.seed(1311)
x <- sample.int(1000000, 1000000, replace = FALSE)
new_val = x[13]
print(new_val)
x[length(x) + 1] <- new_val
print(length(x))
write.table(x, "example_array.txt", row.names = FALSE, col.names = FALSE)
