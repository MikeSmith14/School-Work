//
//  WeightViewController.swift
//  Health Hearts at Home
//
//  Created by Luis Enrique Alvarez on 2/14/18.
//  Copyright © 2018 Luis Enrique Alvarez. All rights reserved.
//

import UIKit
import Charts

class WeightViewController: UIViewController {

    @IBOutlet weak var textBox: UITextField!
    @IBOutlet weak var linechtChart: LineChartView!
    
    @IBOutlet weak var warnlabel: UILabel!
    
    var numbers1 = [Double]()
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }
    
    override func viewDidAppear(_ animated: Bool) {
        print("IN viewdidapper")
//        numbers1 = UserDefaults.standard.array(forKey: "numbers1")
//        print(numbers1)
        updateGraph1()
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
    @IBAction func submitbtn(_ sender: Any) {
        let input  = Double(textBox.text!) //gets input from the textbox - expects input as double/int
        if input != nil
        {
            
            numbers1.append(input!) //here we add the data to the array.
//            print(numbers1)
//            UserDefaults.standard.set(numbers1, forKey: "numbers1")
            
            updateGraph1()
            textBox.text = ""
            warnlabel.text = ""
            
        } else
        {
            warnlabel.text = "Enter Only values"
            textBox.text = ""
        }
    }
    
    @IBAction func clearbtn(_ sender: Any) {
        numbers1.removeAll()
//        UserDefaults.standard.set(numbers1, forKey:"numbers1");
        
        updateGraph1()
    }
    
    func updateGraph1(){
        //this is the Array that will eventually be displayed on the graph.
        
        var lineChartEntry  = [ChartDataEntry]()
    
        //here is the for loop
        for i in 0..<numbers1.count {
            
            let value = ChartDataEntry(x: Double(i), y: numbers1[i]) // here we set the X and Y status in a data chart entry
            
            lineChartEntry.append(value) // here we add it to the data set
        }
        
        let line1 = LineChartDataSet(values: lineChartEntry, label: "Lbs") //Here we convert lineChartEntry to a LineChartDataSet
        
        line1.colors = [NSUIColor.red] //Sets the colour to red
        
        
        let data = LineChartData() //This is the object that will be added to the chart
        
        data.addDataSet(line1) //Adds the line to the dataSet
        
        
        linechtChart.data = data //finally - it adds the chart data to the chart and causes an update
        
        linechtChart.chartDescription?.text = "Weight Chart" // Here we set the description for the graph
        
    }
}
