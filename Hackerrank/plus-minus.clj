; Complete the plusMinus function below.
(defn plusMinus [arr]
  (let [cnt (count arr)]
    (println (float(/ (count (filter pos? arr)) cnt)))
    (println (float(/ (count (filter neg? arr)) cnt)))
    (println (float(/ (count (filter zero? arr)) cnt)))
  )
)

(def n (Integer/parseInt (clojure.string/trim (read-line))))

(def arr (vec (map #(Integer/parseInt %) (clojure.string/split (read-line) #" "))))

(plusMinus arr)