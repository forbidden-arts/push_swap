# push_swap
<!-- ![dpalmer's 42 stats](https://badge42.vercel.app/api/v2/cli5pb141011308mh1fmi5qrq/stats?cursusId=21&coalitionId=271) -->

![Achievement Unlocked!](./assets/push_swape.png)

<!-- ![dpalmer's 42 push_swap Score](https://badge42.vercel.app/api/v2/cli5pb141011308mh1fmi5qrq/project/2909197) -->

## 🤓 Overview
Remember the [Tower of Hanoi](https://en.wikipedia.org/wiki/Tower_of_Hanoi)? This challenge is in a similar vein, but with some interesting twists:
1. There's only two stacks
2. The stacks rotate
3. It's okay if a larger number is stacked above a smaller one.

## 🧐 So What's the Deal?
- **`sa`** : **swap a** - Swap the two numbers on the top of stack A.
- **`sb`** : **swap b** - Swap the two numbers on the top of stack B.
- **`ss`** : **`sa`** and **`sb`** at the same time.
- **`pa`** : **push a** - Push the first number on stack B to stack A.
- **`pb`** : **push b** - Push the first number on stack A to stack B.
- **`ra`** : **rotate a** - Rotate A counter-clockwise. The first number goes to the end.
- **`rb`** : **rotate b** - Rotate B counter-clockwise. The first number goes to the end.
- **`rr`** : **`ra`** and **`rb`** at the same time.
- **`rra`** : **reverse rotate a** - Rotate A clockwise. The last number goes to the top.
- **`rrb`** : **reverse rotate b** - Rotate B clockwise. The last number goes to the top.
- **`rrr`** : **`rra`** and **`rrb`** at the same time.

I tried several different sorting algos and various shortcuts to get the move count down. Eventually, I settled on a heavily-modified version of QuickSort, which was adapted to the limitations of the project and has a few optimizations builtin that will make obvious moves even though they don't exactly fit the algo.

## 📷 Preview
Here is a visual representation of what the program does.

**Please be aware that the visualizer is a separate component and is not part of this repo.**
![Screenshot](./assets/p_s.gif)

## 💻 Compilation
To compile:

```make```

Remove the object files:

```make clean```

Remove everything:

```make fclean```

## 🤡 Usage
```
$ ./push_swap 4 0 1 3 2

pb
pb
sa
ra
pa
pa
ra
```
There are some limitations that are imposed by the project:

The numbers must be signed integers and must be unique as stated in the PRD. The program will handle several thousands of numbers (tested up to 10k), but it will take a _long time_. There is definitely room for efficiency improvements, but success was determined by fewest moves, not speed.

# I am tempted to revisit this later, as I cannot get it out of my head, and I think I can shave 20% off.

### 📝 License
Go nuts.
