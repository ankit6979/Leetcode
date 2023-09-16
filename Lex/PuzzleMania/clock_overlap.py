def num_of_meets(curr_time, end_time): 
    print(curr_time)
    print(end_time)
    pass 

 

 

curr_time = input().strip().split(":") 

end_time = list(map(int,input().strip().split(":"))) 

print(num_of_meets(curr_time, end_time)) 
