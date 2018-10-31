(defn lonelyinteger [a]
  (first (flatten (filter #(odd? (second %)) (frequencies a))))
)

(def fptr (get (System/getenv) "OUTPUT_PATH"))

(def n (Integer/parseInt (clojure.string/trim (read-line))))

(def a (vec (map #(Integer/parseInt %) (clojure.string/split (read-line) #" "))))

(def result (lonelyinteger a))

(spit fptr (str result "\n") :append true)