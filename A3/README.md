# Tweet Manager

Created by: Daniel Wang, Username:dwang11, ID: 1191584

Assignment: A3  Course: CIS*2500

Last Updated: April 3/2022
***************************************

## Compilation

Compiling the program: In the project directory, use
```
make
```

Running program (requires the above command to be run):

```
./TweetManager
```

Removing all compiled files:

```
make clean
```
***************************************
## Features

These are the following this users can do with the tweet manager.
<details><summary>Basic Commands</summary>

- ### Create Tweet
Add a tweet to the stored list of tweets. Type the username, then the tweet contents. The program will give you the generated id for the tweet.
- ### Display Tweets
Shows the currently stored tweets.
- ### Delete Tweet
Allows you to delete one of the stored tweets.
</details>

<details><summary>Searching & Processing</summary>

- ### Search Tweets

Search all tweets for a given keyword or phrase. Will display each successful match on a separate line.

- ### Counting Stop Words
Count the number of stop words contained within all loaded tweets. The list of words are: 
```
"a","an","and","are","as","at","be","by","for",
"from","has","he","in","is","it","its","of",
"on","that","the","to","was","were","will","with"
```

- ### Sorting all tweets by IDs 
Sorts all of the tweets stored in the application by ascending order.
</details>

<details><summary>Files</summary>

- ### Load Tweets from File
Import all tweets from a `.csv` file. The format of the tweets has to be in order of: `<ID>,<User>,<Tweet>`.
- ### Save Tweets to File
Writes all the currently stored tweets into file (User must type in full file name, e.g. `file.csv`). If a file with the given name currently exists in the directory, it will overwrite the contents.
</details>

***************************************
## Limitations

There are no issues in accordence to the assignment guidelines.

***************************************
## Future Improvments

N/a
