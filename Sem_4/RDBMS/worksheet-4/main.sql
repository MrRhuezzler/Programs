CREATE TABLE authors AS SELECT * FROM c3328.authors;
CREATE TABLE posts AS SELECT * FROM c3328.posts;
CREATE TABLE comments AS SELECT * FROM c3328.com
CREATE TABLE comments AS SELECT * FROM c3328.comments;
CREATE TABLE inlinks AS SELECT * FROM c3328.inlinks;

// --------------------------------------------------------

SET SERVEROUTPUT ON;

//-- 1
DECLARE
  abc INTEGER;
  authorID INTEGER;
  author_detail authors."Authorname"%type;
  CURSOR no_posts IS SELECT "authorID", COUNT(*) FROM authors au INNER JOIN posts p ON au."AuthorID" = p."postID" GROUP BY "authorID";
  CURSOR author_details(idd INTEGER) IS SELECT "Authorname" FROM authors WHERE "AuthorID" = idd;
BEGIN
  OPEN no_posts;
  LOOP
  FETCH no_posts INTO authorID, abc;
    EXIT WHEN no_posts%notfound;
    OPEN author_details(authorID);
    FETCH author_details INTO author_detail;
    dbms_output.put_line(author_detail || ' ' || abc);
    CLOSE author_details;
  END LOOP;
  CLOSE no_posts;
END;


//-- 2
DECLARE
  abc INTEGER;
  authorID INTEGER;
  author_detail authors."Authorname"%type;
  CURSOR posts IS SELECT "authorID" FROM posts WHERE TO_DATE("post_date", 'DD-MM-YYYY') = TO_DATE('31-03-2010', 'DD-MM-YYYY');
  CURSOR author_details(idd INTEGER) IS SELECT "Authorname" FROM authors WHERE "AuthorID" = idd;
BEGIN
  OPEN posts;
  LOOP
  FETCH posts INTO authorID;
    EXIT WHEN posts%notfound;
    OPEN author_details(authorID);
    FETCH author_details INTO author_detail;
    dbms_output.put_line(author_detail || ' ' || abc);
    CLOSE author_details;
  END LOOP;
  CLOSE posts;
END;

//-- 3
DECLARE
  author_detail authors."Authorname"%type;
  CURSOR no_post_authors IS SELECT au."Authorname" FROM authors au LEFT JOIN posts p ON au."AuthorID" = p."authorID" WHERE p."postID" IS NULL;
BEGIN
  OPEN no_post_authors;
  LOOP
  FETCH no_post_authors INTO author_detail;
    EXIT WHEN no_post_authors%notfound;
    dbms_output.put_line(author_detail);
  END LOOP;
  CLOSE no_post_authors;
END;

//-- 4
//-- SELECT p.* FROM authors au INNER JOIN posts p ON au."AuthorID" = p."authorID" WHERE au."Authorname" = 'John Biggs' ORDER BY TO_DATE("post_date", 'DD-MM-YYYY');

DECLARE
  post_details posts%ROWTYPE;
  CURSOR jposts IS SELECT p.* FROM authors au INNER JOIN posts p ON au."AuthorID" = p."authorID" WHERE au."Authorname" = 'John Biggs' ORDER BY TO_DATE("post_date", 'DD-MM-YYYY');
BEGIN
  OPEN jposts;
  LOOP
  FETCH jposts INTO post_details;
    EXIT WHEN jposts%notfound;
    dbms_output.put_line(post_details."postTitle" || ' || ' || post_details."post_date" || ' || ' || post_details."url");
  END LOOP;
  CLOSE jposts;
END;
//-- 5