import sqlite3
conn =sqlite3.connect('Exapmle.db')
cursor=conn.cursor()
cursor.execute("""
CREATE TABLE IF NOT EXISTS STUDENTS (
    ID INTEGER PRIMARY KEY AUTOINCREMENT,
    NAME TEXT,
    MARK INTEGER
)
""")
cursor.execute("INSERT INTO STUDENTS (NAME,MARK) VALUES(?,?)",("Bob",92))
cursor.execute("INSERT INTO STUDENTS (NAME,MARK) VALUES (?,?)",("Alice",92))
conn.commit()

cursor.execute("UPDATE STUDENTS SET MARK=? WHERE ID=?",(90,2))
conn.commit()

cursor.execute("DELETE FROM STUDENTS WHERE ID=2")
conn.commit
cursor.execute ("SELECT * FROM STUDENTS")
rows=cursor.fetchall()
for row in rows:
  print(row)
conn.close()