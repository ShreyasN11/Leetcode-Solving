# @param {Integer[]} nums
# @return {Integer[]}
require 'set'

def find_disappeared_numbers(nums)
    n = nums.length
    res = []
    set = Set.new
    for i in 0...n
        set.add(nums[i])
    end    
    for i in 1...n+1
        if set.include?(i)
            next
        else
            res << i
        end
    end
    return res            
end