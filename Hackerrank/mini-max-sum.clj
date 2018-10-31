(defn miniMaxSum [arr]
  (let [s (sort arr)]
    (print (apply + (take 4 s)))
    (print " ")
    (print (apply + (rest s)))
    )
  )

(def arr (vec (map #(Integer/parseInt %) (clojure.string/split (read-line) #" "))))

(miniMaxSum arr)