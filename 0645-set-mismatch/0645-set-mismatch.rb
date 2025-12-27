# @param {Integer[]} nums
# @return {Integer[]}

require 'set'

def find_error_nums(nums)
    set = Set.new
    n = nums.length
    dupli = -1
    for i in 0...n
        if set.include?(nums[i])
            dupli = nums[i]
        else
            set.add(nums[i])
        end
    end
    for i in 1...n+1
        if set.include?(i)
            next
        else return [dupli, i]
        end
    end            
end