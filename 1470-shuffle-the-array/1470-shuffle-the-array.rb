# @param {Integer[]} nums
# @param {Integer} n
# @return {Integer[]}
def shuffle(nums, n)
    res = []
    for i in 0...n
        res << nums[i]
        res << nums[i+n]
    end 
    return res
end