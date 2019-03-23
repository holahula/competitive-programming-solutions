/*
This problem was asked by Google.

Suppose we represent our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to a file in the abstracted file system. If there is no file in the system, return 0.
*/

package main

import (
	"fmt"
	"regexp"
	"strings"
)

func longestDir(path string) int {

	split := strings.Split(path, "\n")
	ind := make([]int, len(split))
	isFile := make([]bool, len(split))

	numIndent, iter := 0, 0

	for i, w := range split {
		matched := true

		for matched {
			if matched, _ = regexp.Match(`\t`, []byte(w[:2])); matched != false {
				split[i], w = w[1:], w[1:]
				ind[i]++
			} else {
				matched = false
			}
		}
		if f, _ := regexp.Match(`\.`, []byte(w)); f {
			// fmt.Println("contains period: ", w)
			isFile[i] = true
			if ind[i] > numIndent {
				numIndent = ind[i]
				iter = i
			}
		}
	}

	if iter == 0 {
		return 0
	}

	fmt.Println(iter, numIndent, split[iter])
	ans := split[iter]
	for i := iter; i > -1; i-- {
		if ind[i] == numIndent-1 && !isFile[i] {
			ans = split[i] + "/" + ans
			numIndent--
		}
	}

	// fmt.Println(ind)
	// fmt.Println(split)
	// fmt.Println(isFile)

	// fmt.Println(ans, len(ans))

	return len(ans)
}

func main() {
	path := "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
	longestDir(path)

	path = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
	longestDir(path)

}
