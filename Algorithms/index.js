let nums = [5, 4, 1, 3, 6, 2];

function insertionSort(n) {
    for (let i = 1; i < n.length; i++) {
        const key = n[i];
        let j = i - 1;
        while (j > -1 && n[j] > key) {
            n[j + 1] = n[j];
            j--;
        }
        n[j + 1] = key;
    }
}


function bubbleSort(n) {
    let bool = true;
    while (bool) {
        bool = false;
        for (let i = 0; i < n.length; i++) {
            if (n[i] > n[i + 1]) {
                const right = n[i + 1];
                n[i + 1] = n[i];
                n[i] = right;
                bool = true;
            }
        }
    }
}

// insertionSort(nums)
bubbleSort(nums)
console.log(nums);



